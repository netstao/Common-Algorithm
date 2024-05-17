#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
        string name;
        int score;

        /**
         * @brief 比较当前对象与参数对象s的score成员变量大小
         *
         * 通过比较当前对象的score成员变量与参数对象s的score成员变量的大小，
         * 判断当前对象是否大于参数对象s。
         *
         * @param s 用于比较的另一个Student对象
         *
         * @return 如果当前对象的score小于参数对象s的score，则返回true；否则返回false
         */
        bool operator>(const Student& s) const {
            // 比较当前对象的score成员变量与参数对象s的score成员变量
            return score > s.score;
        }

        bool operator<(const Student& s) const {
            // 比较当前对象的score成员变量与参数对象s的score成员变量
            return score < s.score;
        }

        /**
         * @brief 重载输出运算符<<，用于输出学生对象
         *
         * 将学生对象的姓名和分数输出到输出流中，并返回输出流对象以便链式调用。
         *
         * @param os 输出流对象
         * @param s 学生对象
         *
         * @return 输出流对象，以便链式调用
         */
        friend  ostream& operator<<(ostream& os, const Student& s) {
            // 将学生对象的姓名和分数输出到输出流中
            os << "Student:" << s.name << " Score" << s.score<<endl;
            // 返回输出流对象，以便链式调用
            return os;
        }
};
