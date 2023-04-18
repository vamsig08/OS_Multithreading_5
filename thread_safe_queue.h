#ifndef OSASSIGNMENT5_THREAD_SAFE_QUEUE_H
#define OSASSIGNMENT5_THREAD_SAFE_QUEUE_H

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <utility>

template<class T>
class MultiThreadSafeQueue
{
    public:
        explicit MultiThreadSafeQueue(size_t capacity = INT_MAX);
        void push(T element);
        T pop();
        bool is_empty();

    private:
        std::mutex mutex;
        std::condition_variable not_empty;
        std::condition_variable not_full;
        std::queue<T> queue;
        std::size_t capacity{};
};

template<class T>
MultiThreadSafeQueue<T>::MultiThreadSafeQueue(size_t capacity) {
    this->capacity = capacity;
}

template<class T>
void MultiThreadSafeQueue<T>::push(T element)
{
    std::unique_lock<std::mutex> lock(mutex);
    not_full.wait(lock, [this] { return queue.size() < capacity; });

    queue.push(element);

    lock.unlock();
    not_empty.notify_one();
}

template<class T>
T MultiThreadSafeQueue<T>::pop()
{
    std::unique_lock<std::mutex> lock(mutex);
    not_empty.wait(lock, [this] { return !queue.empty(); });

    T value = queue.front();
    queue.pop();

    lock.unlock();
    not_full.notify_one();

    return value;
}

template<class T>
bool MultiThreadSafeQueue<T>::is_empty() {
    std::lock_guard<std::mutex> lock(mutex);
    return queue.empty();
}

#endif //OSASSIGNMENT5_THREAD_SAFE_QUEUE_H
