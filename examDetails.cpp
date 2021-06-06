#include <iostream>
#include "examDetails.h"

ExamDetails::ExamDetails(int courseId, int monthOfExam, int dateOfExam, double startTime, int duration,
                         std::string link) : course_id(courseId), month_of_exam(monthOfExam),
                                             day_of_exam(dateOfExam), start_time(startTime),
                                             duration(duration), zoom_link(link) {}

int ExamDetails::operator-(const ExamDetails exam_2) const {
    return 0;
}

const std::string &ExamDetails::getLink() const {
    return zoom_link;
}

void ExamDetails::setLink(const std::string &zoomLink) {
    zoom_link = zoomLink;
}

int hours(ExamDetails exam) {
    return (int) exam.start_time;
}

int minutes(ExamDetails exam) {
    int minutes = (int) exam.start_time * 100;
    minutes = minutes % 100;
    return minutes;
}

std::ostream &operator<<(std::ostream &os, const ExamDetails &exam) {
    os << "Course Number: " << exam.course_id << std::endl << "Time: " << exam.day_of_exam << "." << exam.month_of_exam
       << "at " << hours(exam) << ":" << minutes(exam) << std::endl << "Duration: " << exam.duration << ":00"
       << std::endl << "Zoom Link: " << exam.zoom_link;
    return os;
}

int ExamDetails::operator-(const ExamDetails other) const {
    int months_gap = this->month_of_exam - other.month_of_exam;
    int days_gap = this->day_of_exam - other.day_of_exam;
    return months_gap + days_gap;

}

