#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int n, k;

// 定义一个结构体来存储同学信息
struct Student {
    char teamId;
    int theoryScore;
    int teamProjectScore;
    double finalScore;
    Student(char id, int theory, int teamScore) : teamId(id), theoryScore(theory), teamProjectScore(teamScore) {
        finalScore = round(theoryScore * 0.6 + teamProjectScore * 0.4);
    }
};

// 自定义比较函数
bool compareStudents(const Student& a, const Student& b) {
    if (a.finalScore != b.finalScore) {
        return a.finalScore > b.finalScore;
    }
    return a.teamId < b.teamId;
}
void solution() {
    map<char, vector<int>> hash;
    cin >> n >> k;
    //各组成绩
    for (int i = 0;i < n;i++) {
        int grade;
        char team;
        cin >> grade >> team;
        hash[team].push_back(grade);
    }
    //队伍打分成绩
    vector<vector<int>> scores(k, vector<int>(k, 0));
    for (int i = 0;i < k;i++) {
        for (int j = 0; j < k;j++) {
            cin >> scores[i][j];
        }
    }

    vector<int> avg_team;
    //互相打分平均分 Calc
    for (int i = 0;i < k;i++) {
        int sum = 0;
        for (int j = 0; j < k;j++) {
            sum += scores[j][i];
        }
        sum /= k;
        avg_team.push_back(sum);
    }



    //分差大于15剔除
    for (int i = 0;i < k;i++) {
        for (int j = 0;j < k;j++) {
            if (abs(scores[j][i] - avg_team[i]) > 15) {
                scores[j][i] = 0;
            }
        }
    }
    //Calc 剔除超过15分的队伍打分后的平均分
    for (int i = 0;i < k;i++) {
        double s_sum = 0;
        int cnt = 0;
        for (int j = 0;j < k;j++) {
            if (scores[j][i] == 0) {
                cnt++;
                continue;
            }
            s_sum += scores[j][i];
        }
        s_sum = s_sum / (k - cnt);
        s_sum = round(s_sum);
        avg_team[i] = s_sum;
    }

    // 存储每个同学的信息
    vector<Student> students;
    int teamIndex = 0;
    for (const auto& h : hash) {
        char teamId = h.first;
        const vector<int>& theoryScores = h.second;
        int teamProjectScore = avg_team[teamIndex++];
        for (int theoryScore : theoryScores) {
            students.emplace_back(teamId, theoryScore, teamProjectScore);
        }
    }

    // 对同学进行自定义排序
    sort(students.begin(), students.end(), compareStudents);

    // 输出排序后的同学信息
    for (const auto& student : students) {
        cout << student.teamId << " " <<  student.finalScore << endl;
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solution();
    return 0;
}