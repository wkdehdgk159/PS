//https://school.programmers.co.kr/learn/courses/30/lessons/92341
//주차 요금 계산(Level 2, 문자열)

import math

def solution(fees, records):
    answer = []
    std_m = fees[0]
    std_f = fees[1]
    unit_m = fees[2]
    unit_f = fees[3]
    
    fee_dict = {}
    
    def how_much(minutes, std_m = std_m, std_f = std_f, unit_m = unit_m, unit_f = unit_f):
        fee = 0
        if minutes <= std_m:
            return std_f
        else:
            return std_f + math.ceil((minutes - std_m) / unit_m) * unit_f
        
    for i in range(len(records), 0, -1):
        a = records[i-1].split(' ')
        t = a[0].split(':')
        minute = int(t[0]) * 60 + int(t[1])
        car_num = int(a[1])
        in_out = a[2]
        
        if in_out == "IN":
            #차량이 나간 기록이 없으면
            if car_num not in fee_dict:
                fee_dict[car_num] = 1439 - minute
            else:
                fee_dict[car_num] -= minute
        else:
            if car_num not in fee_dict: 
                fee_dict[car_num] = minute
            else:
                fee_dict[car_num] += minute
        
    fee_dict = sorted(fee_dict.items())
    for a in fee_dict:
        answer.append(how_much(a[1]))
    
    return answer

//조금 귀찮은 문자열 문제. 문자열은 Python으로 하자...