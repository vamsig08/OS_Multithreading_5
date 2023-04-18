#include <iostream>
#include <fstream>
#include <thread>
#include "thread_safe_queue.h"

using namespace std;

MultiThreadSafeQueue<int> tsq;

void start_reader(const string& input_file) {
    ifstream file;
    string line;

    file.open(input_file, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            int num = stoi(line);
            // cout << num << endl;
            tsq.push(num);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << input_file << endl;
        cout << "Terminating..." << endl;
        exit(1);
    }
}

void start_writer() {

    ofstream even_file;
    ofstream odd_file;
    ofstream positive_file;
    ofstream negative_file;
    ofstream squared_file;
    ofstream cube_file;

    even_file.open("even.out", ios::out);
    odd_file.open("odd.out", ios::out);
    positive_file.open("positive.out", ios::out);
    negative_file.open("negative.out", ios::out);
    squared_file.open("square.out", ios::out);
    cube_file.open("cube.out", ios::out);

    do {
        int value = tsq.pop();

        // ood/even
        if(value % 2 == 0)
            even_file << value << endl;
        else
            odd_file << value << endl;

        // positive/negative
        if (value > 0)
            positive_file << value << endl;
        else
            negative_file << value << endl;

        // squared
        squared_file << value * value << endl;

        // cube
        cube_file << value * value * value << endl;
    }while(!tsq.is_empty());

    even_file.close();
    odd_file.close();
    positive_file.close();
    negative_file.close();
    squared_file.close();
    cube_file.close();
}


int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 2) {
        cout << "Usage: assignment_5 <path_to_source_file>" << endl;
        cout << "Any more or less parameters are invalid" << endl << endl;
    }

    string input_file;

    input_file = argv[1];
    cout << "Input file: " << input_file << endl;

    std::thread reader_thread(start_reader, input_file);
    std::thread writer_thread(start_writer);

    reader_thread.join();
    writer_thread.join();
}




