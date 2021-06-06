#include <iostream>
#include "examDetails.h"

ExamDetails::ExamDetails(int courseId, int monthOfExam, int dayOfExam, double startTime, int duration,
                         std::string zoomLink) : course_id(courseId), month_of_exam(monthOfExam),
                                                 day_of_exam(dayOfExam), start_time(startTime),
                                                 duration(duration), zoom_link(zoomLink) {
    if (courseId < 0) {
        throw InvalidArgsException();
    }
    if (monthOfExam <= 0 || monthOfExam > 30 || dayOfExam <= 0 || dayOfExam > 30) {
        throw InvalidDateException();
    }
    if (!(((int) (startTime * 10) % 10) == 0 || ((int) (startTime * 10) % 10) == 5)) {
        throw InvalidTimeException();
    }
    if (duration < 0) {
        throw InvalidTimeException();
    }
}


bool ExamDetails::operator<(const ExamDetails &exam) const {
    if (month_of_exam < exam.month_of_exam) {
        return true;
    }
    if (month_of_exam > exam.month_of_exam) {
        return false;
    }
    if (day_of_exam < exam.day_of_exam) {
        return true;
    }
    if (day_of_exam > exam.day_of_exam) {
        return false;
    }
    return start_time < exam.start_time;
}

const std::string &ExamDetails::getLink() const {
    return zoom_link;
}

void ExamDetails::setLink(const std::string &zoomLink) {
    zoom_link = zoomLink;
}

std::string minutes(double time) {
    return ((int) (time * 10)) % 10 ? "30" : "00";
}

ExamDetails ExamDetails::makeMatamExam() {
    return ExamDetails(234124, 7, 28, 13, 3, "http://tinyurl.com/59hzps6m");
}

ExamDetails &ExamDetails::operator=(const ExamDetails &exam_2) = default;

std::ostream &operator<<(std::ostream &os, const ExamDetails &exam) {
    os << std::endl << "Course Number: " << exam.course_id << std::endl << "Time: " << exam.day_of_exam
       << "."
       << exam.month_of_exam << " at " << (int) exam.start_time << ":" << minutes(exam.start_time) << std::endl
       << "Duration: " << exam.duration << ":00" << std::endl << "Zoom Link: " << exam.zoom_link;
    return os;
}

int ExamDetails::operator-(const ExamDetails &other) const {
    int months_gap = this->month_of_exam - other.month_of_exam;
    int days_gap = this->day_of_exam - other.day_of_exam;
    return months_gap + days_gap;

}

