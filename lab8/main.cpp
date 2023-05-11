class Fueltank:
    def __init__(self, fueltank_capacity=3000, gas_grade=98):
        self._fueltank_capacity = fueltank_capacity
        self._gas_grade = gas_grade
        
    def fuel_up(self, v, gas):
        if gas == self._gas_grade and v == self._fueltank_capacity:
            print(f"fuel_up: {self._fueltank_capacity} Gas_grade: {self._gas_grade}")
        elif gas != self._gas_grade and v == self._fueltank_capacity:
            print(f"Error: Gas_grade: {gas} Correct Gas_grade: {self._gas_grade}")
        elif gas == self._gas_grade and v != self._fueltank_capacity:
            print(f"Error: FueltankCapacity: {self._fueltank_capacity} but fuel up: {v}")
            print(f"fuel_up: {self._fueltank_capacity} Gas_grade: {self._gas_grade}")
        elif gas != self._gas_grade and v != self._fueltank_capacity:
            print(f"Error: FueltankCapacity: {self._fueltank_capacity} but fuel up: {v}")
            print(f"Error: Gas_grade: {gas} Correct Gas_grade: {self._gas_grade}")
            
    def set_gas_grade(self, gas_grade):
        self._gas_grade = gas_grade
        print(f"Set Gas_grade: {self._gas_grade}")
        
    def get_gas_grade(self):
        return self._gas_grade


class AudiCar:
    def __init__(self, model, year, max_seating):
        self._model = model
        self._year = year
        self._max_seating = max_seating
        self._brand = "Audi" #車子類別
        self._fuel_tank = Fueltank()
        
    def get_max_seating(self):
        return self._max_seating
    
    def get_brand(self):
        return self._brand
    
    def get_gas_grade(self):
        return self._fuel_tank.get_gas_grade()
    
    def set_gas_grade(self, gas_grade):
        return self._fuel_tank.set_gas_grade(gas_grade)
    
    def fuel_up(self, v, gas):
        return self._fuel_tank.fuel_up(v, gas)


car_2 = AudiCar("A1", 2021, 2)
print(car_2.get_brand(), ": Gas_grad = ", car_2.get_gas_grade())
car_2.set_gas_grade(95)
print(car_2.get_brand(), ": Gas_grad = ", car_2.get_gas_grade())
car_2.fuel_up(300, 95)
