# 1.student.mark.py

def get_student_details():
    name = input("Enter student name: ")
    id = input("Enter student ID: ")
    return (name, id)

def get_course_details():
    course_name = input("Enter course name: ")
    credit_hours = float(input("Enter credit hours: "))
    return (course_name, credit_hours)

def get_student_marks(courses):
    marks = {}
    for course in courses:
        mark = float(input(f"Enter mark for {course}: "))
        marks[course] = mark
    return marks

def calculate_gpa(marks, credits):
    total_grade_points = 0
    total_credits = 0
    for course, mark in marks.items():
        grade_points = mark_to_grade_point(mark)
        credit_hours = credits[course]
        total_grade_points += grade_points * credit_hours
        total_credits += credit_hours
    return total_grade_points / total_credits

def mark_to_grade_point(mark):
    if mark >= 90:
        return 4.0
    elif mark >= 80:
        return 3.0
    elif mark >= 70:
        return 2.0
    elif mark >= 60:
        return 1.0
    else:
        return 0.0

students = []
while True:
    choice = input("Enter 1 to add a new student, 2 to display student details, or 3 to quit: ")
    if choice == "1":
        student = {}
        name, id = get_student_details()
        student["name"] = name
        student["id"] = id
        courses = []
        while True:
            choice = input("Enter 1 to add a new course, 2 to finish adding courses: ")
            if choice == "1":
                course_name, credit_hours = get_course_details()
                courses.append(course_name)
                student[course_name] = {"credit_hours": credit_hours}
            elif choice == "2":
                break
            else:
                print("Invalid choice")
        marks = get_student_marks(courses)
        for course, mark in marks.items():
            student[course]["mark"] = mark
        gpa = calculate_gpa(marks, {course: student[course]["credit_hours"] for course in courses})
        student["gpa"] = gpa
        students.append(student)
        print("Student details added successfully")
    elif choice == "2":
        if not students:
            print("No student details found")
            continue
        for i, student in enumerate(students):
            print(f"{i+1}. Name: {student['name']}, ID: {student['id']}, GPA: {student['gpa']}")
            for course in student:
                if course not in ["name", "id", "gpa"]:
                    print(f"   {course}: {student[course]['mark']}")
    elif choice == "3":
        break
    else:
        print("Invalid choice")
