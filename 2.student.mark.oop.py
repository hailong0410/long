class Student:
    def __init__(self, id, name, dob):
        self.id = id
        self.name = name
        self.dob = dob
        self.marks = {}

class Course:
    def __init__(self, id, name):
        self.id = id
        self.name = name
        self.marks = {}

class StudentMarkManagementSystem:
    def __init__(self):
        self.students = {}
        self.courses = {}

    def input_student_info(self):
        n = int(input("Enter the number of students: "))
        for i in range(n):
            id = input("Enter student ID: ")
            name = input("Enter student name: ")
            dob = input("Enter student date of birth (YYYY-MM-DD): ")
            self.students[id] = Student(id, name, dob)

    def input_course_info(self):
        n = int(input("Enter the number of courses: "))
        for i in range(n):
            id = input("Enter course ID: ")
            name = input("Enter course name: ")
            self.courses[id] = Course(id, name)

    def input_marks(self):
        course_id = input("Enter course ID: ")
        if course_id not in self.courses:
            print("Course not found.")
            return
        for id, student in self.students.items():
            mark = input("Enter mark for student {}: ".format(id))
            student.marks[course_id] = mark
            self.courses[course_id].marks[id] = mark

    def list_courses(self):
        print("Courses:")
        for id, course in self.courses.items():
            print("{} - {}".format(id, course.name))

    def list_students(self):
        print("Students:")
        for id, student in self.students.items():
            print("{} - {}".format(id, student.name))

    def show_student_marks(self):
        course_id = input("Enter course ID: ")
        if course_id not in self.courses:
            print("Course not found.")
            return
        print("Marks for course {}:".format(self.courses[course_id].name))
        for id, mark in self.courses[course_id].marks.items():
            print("{} - {}: {}".format(id, self.students[id].name, mark))

    def start(self):
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
                self.input_student_info()
            elif choice == "2":
                self.input_course_info()
            elif choice == "3":
                self.input_marks()
            elif choice == "4":
                self.list_courses()
            elif choice == "5":
                self.list_students()
            elif choice == "6":
                self.show_student_marks()
            elif choice == "0":
                break
            else:
                print("Invalid choice. Please try again.")

sms = StudentMarkManagementSystem()
sms.start()
