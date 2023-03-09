
students = {}
courses = {}
1

def input_student_info():
    n = int(input("Enter the number of students: "))
    for i in range(n):
        id = input("Enter student ID: ")
        name = input("Enter student name: ")
        dob = input("Enter student date of birth (YYYY-MM-DD): ")
        students[id] = {"name": name, "dob": dob, "marks": {}}

def input_course_info():
    n = int(input("Enter the number of courses: "))
    for i in range(n):
        id = input("Enter course ID: ")
        name = input("Enter course name: ")
        courses[id] = {"name": name, "marks": {}}


def input_marks():
    course_id = input("Enter course ID: ")
    if course_id not in courses:
        print("Course not found.")
        return
    for id, student in students.items():
        mark = input("Enter mark for student {}: ".format(id))
        student["marks"][course_id] = mark
        courses[course_id]["marks"][id] = mark


def list_courses():
    print("Courses:")
    for id, course in courses.items():
        print("{} - {}".format(id, course["name"]))

def list_students():
    print("Students:")
    for id, student in students.items():
        print("{} - {}".format(id, student["name"]))


def show_student_marks():
    course_id = input("Enter course ID: ")
    if course_id not in courses:
        print("Course not found.")
        return
    print("Marks for course {}:".format(courses[course_id]["name"]))
    for id, mark in courses[course_id]["marks"].items():
        print("{} - {}: {}".format(id, students[id]["name"], mark))


while True:
    print("\nStudent Mark Management System\n")
    print("1. Input student information")
    print("2. Input course information")
    print("3. Input marks for a course")
    print("4. List courses")
    print("5. List students")
    print("6. Show student marks for a course")
    print("0. Exit")
    choice = input("Enter your choice: ")
    if choice == "1":
        input_student_info()
    elif choice == "2":
        input_course_info()
    elif choice == "3":
        input_marks()
    elif choice == "4":
        list_courses()
    elif choice == "5":
        list_students()
    elif choice == "6":
        show_student_marks()
    elif choice == "0":
        break
    else:
        print("Invalid choice. Please try again.")
