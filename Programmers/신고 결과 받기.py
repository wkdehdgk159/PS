//https://school.programmers.co.kr/learn/courses/30/lessons/92334
//신고 결과 받기(Level 1, 문자열)

def solution(id_list, report, k):
    id_dict = {}
    mail_dict = {}
    for id in id_list:
        id_dict[id] = []
        mail_dict[id] = 0
        
    for re in report:
        reporting, reported = re.split(' ')
        if reporting not in id_dict[reported]:
            id_dict[reported].append(reporting)
    
    for id in id_dict:
        if len(id_dict[id]) >= k:
            for i in id_dict[id]:
                mail_dict[i] += 1
    answer = []
    
    for i in mail_dict:
        answer.append(mail_dict[i])
    return answer