#include <string>
#include <algorithm>

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto getDayNumber = [](const std::string& date) {
            static const int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int month = std::stoi(date.substr(0, 2));
            int day = std::stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };

        int aliceStart = getDayNumber(arriveAlice);
        int aliceEnd = getDayNumber(leaveAlice);
        int bobStart = getDayNumber(arriveBob);
        int bobEnd = getDayNumber(leaveBob);

        int startOverlap = std::max(aliceStart, bobStart);
        int endOverlap = std::min(aliceEnd, bobEnd);

        return std::max(0, endOverlap - startOverlap + 1);
    }
};