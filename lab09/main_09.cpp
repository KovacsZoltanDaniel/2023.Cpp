#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;
void main1() {
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    auto berry =  std::find_if(fruits.begin(), fruits.end(), [](const string& fruit) {
        return  fruit.find("berry") != string::npos;
    });
    cout << (berry - fruits.begin()) << endl;
}
void main2() {
    vector<int> numbers {2,2,2,4,8};
    cout << all_of(numbers.begin(), numbers.end(), [](int i) {
        return (i & 1) == 0;
    });
}
void main3() {
    vector<int> numbers {2,2,4,8};
    for_each(numbers.begin(), numbers.end(), [](int &i) {
        i = i * 2;
    });
    for_each(numbers.begin(), numbers.end(), [](int i) {
        cout << i << " ";
    });
}
void main4() {
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "Auugst", "September", "October", "November", "December"
    };
    cout << count_if(months.begin(), months.end(), [](const string& month) {
        return month.length() == 5;
    });
}
void main5() {vector<float> numbers {9.0, 3.5,4.1,8.5};
    std::sort(numbers.begin(), numbers.end(), [](float a, float b) {
        return a < b;
    });
    for (float number : numbers) {
        cout << number << " ";
    }
    cout << endl;
    vector<float> numbers1 {9.0, 45.5,4.1,11.5};
    greater<float> greater;
    std::sort(numbers1.begin(), numbers1.end(),greater);
    for (float number : numbers1) {
        cout << number << " ";
    }
}
void main6() {
    vector<pair<string,float>>months{
            {"January", -1.0},
            {"February", -0.5},
            {"March", 3.0},
            {"April", 4.0},
            {"May", 5.0},
            {"June", 19.0},
            {"July", 18.0},
            {"Auugst", 25.0},
            {"September", 9.0},
            {"October", 10.0},
            {"November", 6.0},
            {"December", -3.0}
    };
    sort(months.begin(), months.end(), [](pair<string,float> a, pair<string,float> b) {
        return a.second < b.second;
    });
    for (pair<string,float> month : months) {
        cout << month.first << " " << month.second << endl;
    }
}
void main7() {
    vector<float> numbers1 {-9.0, 45.5,4.1,-11.5};
    sort(numbers1.begin(), numbers1.end(),[](float a, float b) {
        return abs(a) < abs(b);
    });
    for (float i : numbers1) {
        cout << i << " ";
    }
}
void main8() {
    vector<string>months{
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "Auugst",
            "September",
            "October",
            "November",
            "December"
    };
    for_each(months.begin(), months.end(), []( string& month) {
        month[0] = ::tolower(month[0]);
    });
    for (const auto & month : months) {
        cout << month << " ";
    }
}
void main9() {

}
int main() {
    // main1();
    // main2();
    // main3();
    // main4();
    // main5();
    // main6();
    // main7();
    // main8();
    string abc = "abcdefghijklmnopqrstuvwxyz";
    shuffle(abc.begin(), abc.end(),random_device());
    cout << abc << endl;
    char inv[256] = {0};
    std::for_each(abc.begin(), abc.end(),[&inv,&abc](char i) {
        inv[i] = abc.find(i);
        inv[::tolower(i)] = abc.find(i);

    });
    cout << inv << endl;

    return 0;
}