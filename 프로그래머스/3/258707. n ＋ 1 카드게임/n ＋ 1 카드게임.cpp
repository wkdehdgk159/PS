#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    int n = cards.size();
    
    //가지고 있으면 2, 후보군이면 1, 아직 도달하지 않은 카드면 0, 사용했으면 -1
    int arr[1001] = {0};
    int idx = n / 3 - 1;
    
    //가지고 있는 카드
    vector<int> onhand;
    
    for(int i = 0; i < n / 3; i++) {
        onhand.push_back(cards[i]);
        arr[cards[i]] = 2;
    }
    
    while(idx < n) {
        
        bool nflag = false;
        
        //일단 현재 카드들 후보군에 추가
        arr[cards[++idx]] = 1;
        arr[cards[++idx]] = 1;
    
        //가지고 있는 카드로 n+1이 완성되어서 코인을 쓰지 않아도 되는 경우 
        for(int i = 0; i < onhand.size(); i++) {
            if(arr[onhand[i]] == 2 && arr[n + 1 - onhand[i]] == 2) {
                answer++;
                //라운드 늘려주고 사용한 카드 삭제
                arr[onhand[i]] = -1;
                arr[n + 1 - onhand[i]] = -1;
                nflag = true;
                break;
            }
        }
        if(nflag) continue;
        
        //코인 하나로 라운드 따내는 경우
        if(coin > 0) {
            for(int i = 0; i < onhand.size(); i++) {
                if(arr[onhand[i]] == 2 && arr[n+1 - onhand[i]] == 1) {
                    answer++;
                    coin--;
                    arr[onhand[i]] = -1;
                    arr[n + 1 - onhand[i]] = -1;
                    nflag = true;
                    break;
                }
            }
        }
        if(nflag) continue;
        
        //코인 두개를 모두 사용해야 라운드 따내는 경우
        if(coin > 1) {
            for(int i = n / 3; i < idx; i++) {
                if(arr[cards[i]] == 1 && arr[n + 1 - cards[i]] == 1) {
                    answer++;
                    coin -= 2;
                    arr[cards[i]] = -1;
                    arr[n+1-cards[i]] = -1;
                    nflag = true;
                    break;
                }
            }
        }
        if(nflag) continue;
        if(nflag == false) break;
    }
    
    if (answer > n / 3 + 1) answer = n / 3 + 1;
    
    return answer;
}

//이미 내가 가지고 있는 카드들로 충분하면 후보군에 넣어두기
//충분하지 않은 상황이 되면 내가 가진 카드들과 pair가 맞는 카드 뽑아오기
//그것도 불가능하면 후보군에서 가능한 2개 뽑아서 다음 라운드로 
//총 3가지 케이스를 검사한다.
//근데 6,7 뽑는게 나을지 5,8 뽑는 게 나을지 어떻게 앎?
// -> 중복을 허용하지 않기 때문에 자기의 짝이 딱 하나씩만 있음. 
//후보군에 저장하는 방식은? 벡터? 맵?
//배열 하나를 만들어서 내가 가지고 있으면 2 후보군이면 1 아직 만나기 전의 카드이면 0
//사용했으면 -1
//가지고 있는 애들 벡터 하나 만들어서 pair 만들어지는지 체크하고, 후보군과 pair 만들어지는지 체크
