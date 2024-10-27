#include <stdio.h>
#include <string.h>

float convert_to_grade_point(int grade){
	if (grade >= 90){
		return 4.0; // A
	} else if (grade >= 85){
		return 3.67; // A-
	} else if (grade >= 80){
		return 3.33; // B+
	} else if (grade >= 75){
		return 3.0; // B
	} else if (grade >= 70){
		return 2.5; // B-
	} else if (grade >= 65){
		return 2.0; // C
	} else if (grade >= 50){
		return 1.0; // D
	} else if (grade <= 49){
		return 0.0; // F
	}
	//no need for extra code after this; the function will always return a value within these conditions.
}

int main(void){
	int num_students, num_courses, grade, sks;
	int c;
	char sks_input[10]; //buffer to hold SKS input as string
	char student_name [24];
	
	printf("Enter the student's name: ");
	scanf("%s", student_name);
	
	//ask for the total number of courses
	printf("Enter the number of courses for %s: ", student_name);
	scanf("%d", &num_courses);
	
	float total_grade_points = 0.0;
	int total_sks = 0;
	
	for (int c = 0; c < num_courses; c++){ //using 'c' here
		printf("Enter grade for class #%d (0-100 scale): ", c + 1);
		scanf("%d", &grade);
		
		//convert numeric grade to grade point
		float grade_point = convert_to_grade_point(grade);
		
		printf("Enter SKS for class #%d: ", c + 1);
		scanf("%d", &sks);

		
		//multiply grade point by SKS and add to total
		total_grade_points += grade_point * sks;
		total_sks += sks; //Add the SKS to the total SKS
	}
	//Calculate GPA by dividing total grade points by the number of courses
	float GPA = total_grade_points / total_sks;
	
	//print the result
	printf("\nStudent Name: %s\n", student_name);
	printf("Total SKS: %d\n", total_sks);
	printf("GPA: %.2f\n\n", GPA);
	
	return 0;
}