scores = [85, 92, 76, 88, 95]

for x in scores:
    print(x)

total=0

for x in scores:
    total+=x
print(total)
print(total/len(scores))

# 添加 88
scores.append(88)

# 删除 92
scores.pop(scores.index(92))
# 修改 76 → 80
scores[scores.index(76)]=80
# 查询 88 是否存在
print(88  in scores)


students = [
    {"name": "Tom", "score": 85},
    {"name": "Alice", "score": 92},
    {"name": "Bob", "score": 76},
    {"name": "Jack", "score": 88}
]

for i in students:
    print(f"{i['name']}: {i['score']}")

total=0
for i in students:
    total+=i["score"]
avg=total/len(students)

pass_student=[]
for i in students:
    if i["score"]>=60:
        pass_student.append(i["name"])
print(pass_student)

high_student=None
high_score=-1
for i in students:
    if i["score"]>high_score:
        high_score=i["score"]
        high_student=i["name"]
print(high_student,high_score)

