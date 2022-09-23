#https://school.programmers.co.kr/learn/courses/30/lessons/72414
#광고 삽입(Level 3, 누적합)

def solution(play_time, adv_time, logs):
    max_timing = 0
    max_sum = 0
    
    h, m, s = play_time.split(":")
    play_t = int(h) * 3600 + int(m) * 60 + int(s)
    
    h, m, s = adv_time.split(":")
    adv_t = int(h) * 3600 + int(m) * 60 + int(s)
    
    sec_list = [0 for i in range(play_t + 1)]
    
    for log in logs:
        h, m, s = log[:8].split(":")
        st_t = int(h) * 3600 + int(m) * 60 + int(s)
        h, m, s = log[9:].split(":")
        end_t = int(h) * 3600 + int(m) * 60 + int(s)
        sec_list[st_t] += 1
        sec_list[end_t] -= 1
    
    #누적합을 이용하여 각 시간초(idx)마다 청취자가 겹치는 수만큼 저장 완료
    for i in range(1, len(sec_list)):
        sec_list[i] = sec_list[i] + sec_list[i-1]
    
    #각 시간초까지 누적 시청시간으로 리스트가 변환 2에서 3초까지의 누적시청시간을 위해서는 sec_list[2] - sec_list[1]
    for i in range(1, len(sec_list)):
        sec_list[i] = sec_list[i] + sec_list[i-1]
        
    for i in range(0, play_t - adv_t):
        if i != 0:
            tmp = sec_list[i + adv_t] - sec_list[i]
            if tmp > max_sum:
                max_sum = tmp
                max_timing = i + 1
        else:
            tmp = sec_list[i + adv_t]
            if tmp > max_sum:
                max_sum = tmp
                max_timing = i
                
    hours = "0"+str(max_timing //3600)
    minutes = "0"+str((max_timing %3600) // 60)
    seconds = "0"+str((max_timing %3600)%60)

    return ":".join([hours[-2:],minutes[-2:],seconds[-2:]])

#잘 풀고 있었는데 파이썬 출력이 익숙치 않아서 계속 헛발만 찼다... 누적합을 잘 이용하여 선형적으로 푸는 문제
