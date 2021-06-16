#include <iosfwd>
#include <gtest/gtest.h>

#define protected public
#define private public
#include "examDetails.h"
#undef private
#undef protected


using std::cout;
using std::endl;
using std::ostringstream;
using mtm::ExamDetails;

TEST(ExamDetails, ExampleSnippet1) {
    const auto exam1 = ExamDetails::makeMatamExam();
    const ExamDetails exam2{104032, 7, 11, 9.5, 3};
    auto exam3 = exam1;

    ostringstream out;
    out << "the difference between MATAM and infi 2m is " << (exam1 - exam2) << " days\n\n";

    auto& closest = (exam1 < exam2) ? exam1 : exam2;

    // make sure exam2 is closest
    EXPECT_EQ(&exam2, &closest);

    out << "your closest exam is:" << endl << closest << endl;

    constexpr auto expected =
            "the difference between MATAM and infi 2m is 17 days\n"
            "\n"
            "your closest exam is:\n"
            "Course Number: 104032\n"
            "Time: 11.7 at 9:30\n"
            "Duration: 3:00\n"
            // TODO Should there be trailing space here?
            "Zoom Link: \n"
            "\n";
    EXPECT_STREQ(expected, out.str().c_str());
}
