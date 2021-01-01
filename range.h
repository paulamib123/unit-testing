#include <iostream>
#include <string>
using namespace std;

// This is a Range class for closed interval i.e [a, b]

class Range {
    protected:
        int start;
        int end;
    public:
        Range(){
            start = end = 0;
        }
        Range(int end) {
            start = 0;
            this->end = end;
        }
        Range(int start, int end) {
            this->start = min(start, end);
            this->end = max(start, end);
        }
        string printRange() {
            string result;
            for (int i = start; i <= end; i++) {
                result += to_string(i) + ", ";
            }
            return result;
        }
        bool containsElement(int ele) {
            return start <= ele && ele <= end;
        }
        bool containsRange(Range b) {
            return b.start >= this->start && b.end <= this->end; 
        }
        bool isLessThan(Range b) {
            return b.start < this->start;
        }
        bool isGreaterThan(Range b) {
            return b.start > this->start;
        }
        bool isEqual(Range b) {
            return b.start == this->start && b.end == this->end;
        }
        bool isDisjoint(Range b){
            return this->start < b.end || this->end < b.start;
        }
        bool isOverlapping(Range b) {
        return !(this->isDisjoint(b));
        } 
};

// This is a Range class for open interval i.e (a, b)

class openInterval: public Range {
    public:
        openInterval(){
                start = end = 0;
        }
        openInterval(int end) {
                start = 0;
                this->end = end - 1;
        }
        openInterval(int start, int end) {
                this->start = min(start + 1, end - 1);
                this->end = max(start + 1, end - 1);
        }
};

// This is a Range class for right open interval i.e (a, b]

class rightOpenInterval: public Range {
    public:
        rightOpenInterval(){
                start = end = 0;
        }
        rightOpenInterval(int end) {
                start = 0;
                this->end = end;
        }
        rightOpenInterval(int start, int end) {
                this->start = min(start + 1, end);
                this->end = max(start + 1, end);
        }
};

// This is a Range class for left open interval i.e [a, b)

class leftOpenInterval: public Range {
    public:
        leftOpenInterval(){
                start = end = 0;
        }
        leftOpenInterval(int end) {
                start = 0;
                this->end = end - 1;
        }
        leftOpenInterval(int start, int end) {
                this->start = min(start, end - 1);
                this->end = max(start, end - 1);
        }
};

// int main() {
//     Range a(3, 7);
//     Range b(5, 7);
//     Range c(8, 10);
//     cout << a.isDisjoint(c) << endl;
//     cout << b.isDisjoint(c) << endl;
// }