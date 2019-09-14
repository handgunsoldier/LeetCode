//
// Created by zhang on 9/4/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

std::vector<std::string> getMemberName(const std::vector<std::vector<std::string>> v){
    std::map<std::string, bool> member_map;
    for(const auto& i: v){
        for(const auto& j: i){
            member_map[j] = true;
        }
    }
    std::vector<std::string> member_name;
    for(const auto& i: member_map){
        member_name.push_back(i.first);
    }
    return member_name;
}

void getMemeber(const std::vector<std::vector<std::string>> v, const std::string& name){
    std::vector<std::string> member_name =  getMemberName(v);
    std::map<std::string,int> name_map;
    int count = 0;
    for(const auto& i: member_name){
        name_map[i] = count;
        count++;
    }

    if(name_map.find(name)==name_map.end())
        return;

    int n = name_map.size();
    std::vector<std::vector<bool>> graph(n, std::vector<bool>(n, false));
    for(const auto& i: v){
        int l = i.size();
        for(int j=0; j<l; j++){
            for(int k=0; k<j; k++){
                int a = name_map.find(i[j])->second;
                int b = name_map.find(i[k])->second;
                graph[a][b] = true;
                graph[b][a] = true;
            }
        }
    }

    int row_first = name_map[name];
    std::vector<bool> visited(n, false);
    visited[row_first] = true;
    std::queue<int> q;
    int level = 0; int last = row_first; int tail = -1;
    q.push(row_first);
    while (!q.empty()){
        int row = q.front();
        q.pop();
        for(int i = 0; i<n; i++){
            if(graph[row][i] and !visited[i]) {
                visited[i] = true;
                q.push(i);
                tail = i;
            }
            if(row == last){
                last = tail;
                level++;
            }
            if(level>2) break;
        }
    }

    for(int i=0; i<n; i++){
        if(visited[i])
            std::cout << member_name[i] <<" ";
    }
    std::cout << std::endl;

//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            std::cout << graph[i][j] ;
//        }
//        std::cout << std::endl;
//    }
}



int main(int argc, char** argv){
    std::vector<std::vector<std::string>> memeber_groups = {
            {"Harry", "Hermione", "Ronald"},
            {"Ronald", "Arthur", "Ginny", "Percy", "Fred", "George","Charlie"},
            {"Lucius", "Draco", "Crab", "Gol", "Kakarov"},
            {"Snape","Kakarov"},
            {"Harry", "James", "Lily"},
            {"Harry", "Penny", "Vernon", "Dali"}
    };

    getMemeber(memeber_groups, "Snape");
//    auto s =  getMemberName(memeber_groups) ;
//    for(auto i: s){
//        std::cout << i << std::endl;
//    }
    int a = -1, b = 1;
    printf("a = %d, b = %d\n", a, b);
    std::swap(a, b);
    printf("a = %d, b = %d\n", a, b);

}