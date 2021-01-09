weight = float(input('Please enter weight in kilograms:'))
height = float(input('Please enter height in meters:'))
bmi = weight / height ** 2
if bmi < 18.5:
    status = 'Underweight'
elif 18.5 <= bmi < 24.9:
    status = 'Normal'
elif 24.9 <= bmi < 30.0:
    status = 'Overweight'
else:
    status = 'Obese'
print('BMI is: ', round(bmi, 2), ', Status is ', status, sep='')
