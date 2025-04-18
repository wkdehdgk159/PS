#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) :
        n(n), prev(prev), next(next) {}
};

stack<Node*> deleted;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    Node* first = new Node(0, NULL, NULL);
    Node* cursor = first;
    
    //연결리스트 만들기
    for(int i = 1; i < n; i++) {
        cursor->next = new Node(i, cursor, NULL);
        cursor = cursor->next;
    }
    
    //현재 위치로 이동
    cursor = first;
    for(int i = 0; i < k; i++) cursor = cursor->next;
    
    string s;
    
    for(int i = 0; i < cmd.size(); i++)  {
        s = cmd[i];
        
        if(s[0] == 'U') {
            int num = stoi(s.substr(2));
            for(int i = 0; i < num; i++) {
                cursor = cursor->prev;
            }
        }
        else if(s[0] == 'D') {
            int num = stoi(s.substr(2));
            for(int i = 0; i < num; i++) {
                cursor = cursor->next;
            }
        }
        else if(s[0] == 'C') {
            deleted.push(cursor);
            
            //맨 앞일 때
            if(cursor -> prev == NULL) {
                cursor = cursor -> next;
                cursor -> prev = NULL;
            }
            
            //맨 뒤일 때
            else if(cursor -> next == NULL) {
                cursor = cursor -> prev;
                cursor -> next = NULL;
            }
            
            //중간 일 때
            else {
                cursor->prev->next = cursor->next;
                cursor->next->prev = cursor->prev;
                cursor = cursor->next;
            }
        }
        else if(s[0] == 'Z') {
            Node* node = deleted.top();
            deleted.pop();
            
            if(node->prev != NULL) node->prev->next = node;
            if(node->next != NULL) node->next->prev = node;
        }
    }

    while(!deleted.empty()) {
        Node* node = deleted.top();
        deleted.pop();
        
        answer[node->n] = 'X';
    }

    return answer;
}

//링크드리스트 만들어서 다루는데 삭제를 진짜 삭제하지 말고 삭제 처리만 하기 -> 근데 배열 두개 만들어서 해도 괜찮지 않나?
//D3갈 때도 삭제한 애들은 포함시키지 않고 하기
//Z는 스택 만들어서 인덱스 저장해놓기
//마지막에 링크드리스트 순회하면서 삭제된 친구들만 X표시