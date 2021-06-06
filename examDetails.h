//
// Created by hagai on 6/5/2021.
//

#ifndef HW2_EXAMDETAILS_H
#define HW2_EXAMDETAILS_H


class Exam {
    int course_num;
    int month_of_exam;
    int dat_of_exam;
    double start_time;
    int duration;
    std::string zoom_link;

public:
    ExamDetails(int course_num, int month_of_exam, int dat_of_exam, double start_time, int duration, std::string
    zoom_link = "");

    ~ExamDetails();

    std::string getLink();

    std::string setLink();

    int operator-(const ExamDetails exam_2) const;

    bool operator<(ExamDetails exam_1, ExamDetails exam_2) const;

    static ExamDetails& makeMatamExam();


};
static ExamDetails& makeMatamExam(){
    ExamDetails* matam= ExamDetails(234124,7,28,13.00,3,"https://tinyurl.com/59hzps6m");
    return matam;
}
#endif //HW2_EXAMDETAILS_H
