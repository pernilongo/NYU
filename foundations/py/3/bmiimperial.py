weight = float(input('Please enter weight in pounds:'))
height = float(input('Please enter height in inches:'))
bmi = (weight*0.453592) / (height*0.0254) ** 2
print('BMI is:', bmi)
