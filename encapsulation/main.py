class Person:
    def __init__(self, name, age):
        self.__name = name  # Private attribute
        self.__age = age  # Private attribute
    
    def get_name(self):  # Public method to access private attribute
        return self.__name
    
    def set_name(self, name):  # Public method to modify private attribute
        self.__name = name
    
    def get_age(self):  # Public method to access private attribute
        return self.__age
    
    def set_age(self, age):  # Public method to modify private attribute
        if age > 0:
            self.__age = age
        else:
            print("Age must be positive!")

# Usage:
person = Person("Alice", 20)
print(person._Person__age)