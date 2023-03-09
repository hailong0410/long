student= {}
courses= {}

def input_student_id():
    n=int(input("Enter the number of students: "))
    for i in range(n):
        id = input("Enter student ID: ")
        name = input("Enter student name: ")
        dob = input("Enter student date of birth (YYYY-MM-DD): ")
        student[id]={"name":name, "dob": dob, "mark":{}}
        
def input_class_id():
    n=int(input("Enter the number of courses: "))
    for i in range(n):
        id = input("Enter course ID: ")
        name = input("Enter course name: ")
        courses[id] = {"name": name, "marks": {}}
        
        