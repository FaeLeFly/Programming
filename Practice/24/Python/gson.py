import json
with open("1in.json", "r") as read_file:
    j = json.load(read_file)
kol=[]
for task in j:
    koli={}
    if task['completed']:
        koli['task_completed']=0
        koli['userId']=0
        bol=True
        count=0
        for num in kol:
            if num['userId']==task['userId']:
                bol=False
                kol[count]['task_completed']+=1
                break
            count +=1
        if bol==True:
            koli['userId']=task['userId']
            koli['task_completed']+=1
            kol.append(koli)
with open("out.json", "w") as write_file:
    json.dump(kol, write_file ,indent=4)
