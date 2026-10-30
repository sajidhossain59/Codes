


info = {
    ("Sajid","CSE"),
    ("Alif","CSE"),
    ("Parag","IEM"),
    ("Moballig","SWE"),
    ("Yeasin","ECO"),
    ("Random","CSE")
}

# List all unique course
set_of_unique_dept = set()

for _,department in info:
    set_of_unique_dept.add(department)

print(set_of_unique_dept)


# List student enrolled in specific subject
set_of_students_in_cse = []
for name,department in info:
    if(department == "CSE"):
        set_of_students_in_cse.append(name)

print(set_of_students_in_cse)


# Create a dictionary
enrolment_dict = {}

for name, department in info:
    enrolment_dict[name] = department

print(enrolment_dict)