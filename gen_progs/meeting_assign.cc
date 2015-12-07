//find the minimium number of meeting rooms required 
//given the vector of meeting timings
//

#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::sort;
using std::max;
using std::min;
using std::map;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


int get_meeting_count(vector<string> v) {
    int result = 0;
    int min_time = INT_MAX;
    int max_time = INT_MIN;
    map<int, int> start_time_freq;
    map<int, int> end_time_freq;

    for(int i = 0; i < v.size(); i++) {
        vector<int> curr_row;
        stringstream ss(v[i]);
        int tmp;
        while(ss >> tmp) {
            curr_row.push_back(tmp);
        }

        min_time = min(curr_row[0], min_time);
        max_time = max(curr_row[1], max_time);
        start_time_freq[curr_row[0]]++;
        end_time_freq[curr_row[1]]++;
    }

    int rooms_req = 0;
    int rooms_avail = 0;

    for(int time_hour = min_time; time_hour <= max_time; time_hour++) {
        rooms_avail += end_time_freq[time_hour];
        rooms_req += (start_time_freq[time_hour] - rooms_avail);
        //cout << "rooms_avail = " << rooms_avail << " rooms_req = " << rooms_req << endl;
        result = max(result, rooms_req);
    }


    return result;
}

int main()
{
    vector<string> meeting_times;
    meeting_times.push_back("2 5");
    meeting_times.push_back("3 4");
    meeting_times.push_back("2 4");
    meeting_times.push_back("2 3");
    meeting_times.push_back("4 7");
    meeting_times.push_back("4 6");
    meeting_times.push_back("6 8");
    meeting_times.push_back("6 7");
    meeting_times.push_back("1 2");
    meeting_times.push_back("1 3");
    meeting_times.push_back("1 5");
    meeting_times.push_back("1 7");

    //cout << meeting_times.size() << endl;
    int result = get_meeting_count(meeting_times);
    cout << "rooms req = " <<  result << endl;

}
