import json
def search_student(students,name):
    if name  in students:
        return students[name]
    return None

def add_student(students,name,score):
    if name in students:
        print(f"{name}已经在表里")
    else :
        students[name]=score

def delete_student(students,name):
    if name in students:
        students.pop(name)
    else:
        print(f"{name}不存在")

def update_score(students,name,score):
    if name not in students:
        print(f"{name}不存在")
    else:
        students[name]=score

def calculate_average(students):
    sum_score=0
    if len(students)==0:
        return 0
    for x in students:
        sum_score+=students[x]
    return sum_score/len(students)

def save(students):
    students_json=json.dumps(students)
    with open("students.json","w") as f:
        f.write(students_json)

def load():
    try:
        with open("students.json","r") as f:
            students_json=f.read()
            students=json.loads(students_json)
    except FileNotFoundError:
        print("文件不存在")
        students={}
    except json.JSONDecodeError:
        print("json文件损坏")
        students={}
    return students

students=load()
while True:
    print('''===== 学生成绩管理系统 =====
1. 添加学生
2. 删除学生
3. 修改成绩
4. 查询学生
5. 查看所有学生
6. 计算平均分
0. 退出
    ''')
    get_input = input("请选择：")
    if get_input=="0":
        save(students)
        break
    elif get_input=="1":
        name =input("请输入名字：")
        score =int(input("请输入成绩："))
        add_student(students,name,score)
    elif get_input=="2":
        name =input("请输入名字：")
        delete_student(students,name)
    elif get_input=="3":
        name =input("请输入名字：")
        score =int(input("请输入成绩："))
        update_score(students,name,score)
    elif get_input=="4":
        name =input("请输入名字：")
        score=search_student(students,name)
        if score is not None:
            print(f"{name}: {score}")
        else:
            print("找不到该学生")
    elif get_input=="5":
        for student, score in students.items():
            print(f"{student}: {score}")
    elif get_input=="6":
        result=calculate_average(students)
        print(f"平均分是{result}")
    else :
        print("请重新输入")
    save(students)
        
