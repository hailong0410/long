class Person:
    def __init__(self, n, a):
        self.name = n
        self.age = a
    def describe(self):
        print("Name:", self.name)
        print("Age:", self.age)
    def __lt__(self, other):
        return self.age < other.age
    def __str__(self):
        return f"My name is {self.name}. I am {self.age}."
macron = Person("Emmanuel Macron", 43)
macron.describe()
print(macron)
biden = Person("Joe Biden", 78)
print(f"Macron is younger: {macron < biden}")