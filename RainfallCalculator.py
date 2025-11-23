#################################################################
# Class: CMSC135
# Instructor: Ongomefen Andrea 
# Program Assignment: 3
# Program Name: OngomefenAndreaLab3.py
# Author: Student Ongomefen Andrea
# Due Date: 10/17/2025
# Description: avg yearly rainfall calculator
# I pledge that I have completed the programming assignment independently.
# I have not copied the code from a student or any source.
# I have not given my code to any student.
# Print your Name here: ANDREA ONGOMEFEN
#
# Pseudocode:
# START
# SET total_rainfall = 0.0
# SET total_months = 0
# GET number_of_years
# FOR year IN range(1, number_of_years + 1):
# DISPLAY for year
# FOR month IN range(12):
# GET monthly_rainfall
# ADD monthly_rainfall TO total_rainfall
# COUNT total months in loop
# CALCULATE average_rainfall = total_rainfall / total_months
# DISPLAY Number of months
# DISPLAY Total inches of rainfall
# DISPLAY Average rainfall per month
# END
###################################################################


total_rainfall = 0.0
total_months = 0
number_of_years = int(input("Enter number of years: "))
for year in range(1, number_of_years + 1):
    print("For year", year, ":")
    for month in range (1, 13):
        monthly_rainfall = float(input("Enter the rainfall amount for the month: "))
        total_rainfall += monthly_rainfall
        total_months = total_months + 1
avg_rainfall = total_rainfall / total_months
print ("Number of months:", total_months, " inches")
print ("Total inches of rainfall:", total_rainfall, " inches")
print (f"Average rainfall per month: {avg_rainfall:.2f} inches")
