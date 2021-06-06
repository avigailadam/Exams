
#ifndef HW2_EXAMDETAILS_H
#define HW2_EXAMDETAILS_H
#include <string>
#include <ostream>

class ExamDetails {
    int course_id;
    int month_of_exam;
    int day_of_exam;
    double start_time;
    int duration;
    std::string zoom_link;

public:
    ExamDetails(int courseId, int monthOfExam, int dayOfExam, double startTime, int duration,
                std::string link = "");

    ~ExamDetails();

    const std::string &getLink() const;

    void setLink(const std::string &zoomLink);


    int operator-(const ExamDetails other) const;

    bool operator<(ExamDetails exam) const;

    static ExamDetails &makeMatamExam();
    std::ostream& operator<<(std::ostream& os, const ExamDetails exam);

    friend std::ostream &operator<<(std::ostream &os, const ExamDetails &details);
    friend  int hours(ExamDetails exam);
    friend  int minutes(ExamDetails exam);


};

#endif //HW2_EXAMDETAILS_H
