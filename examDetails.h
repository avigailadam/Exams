
#ifndef HW2_EXAMDETAILS_H
#define HW2_EXAMDETAILS_H

#include <string>
#include <ostream>
namespace mtm {
    class ExamDetails {
        int course_id;
        int month_of_exam;
        int day_of_exam;
        double start_time;
        int duration;
        std::string zoom_link;

    public:

        ExamDetails(int course_num, int month_of_exam, int day_of_exam, double start_time, int duration, std::string
        zoom_link = "");

        ExamDetails(const ExamDetails &exam) = default;

        ~ExamDetails() = default;


        const std::string &getLink() const;


        void setLink(const std::string &zoomLink);

        int operator-(const ExamDetails &other) const;

        bool operator<(const ExamDetails &exam) const;

        ExamDetails &operator=(const ExamDetails &exam_2);

        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &details);


        static ExamDetails makeMatamExam();

        class InvalidDateException {
        };

        class InvalidTimeException {
        };

        class InvalidArgsException {
        };
    };

}
#endif //HW2_EXAMDETAILS_H
