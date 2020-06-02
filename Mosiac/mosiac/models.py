from django.db import models
from djongo import models
from django.utils import timezone

class restaurant(models.Model):
    restaurant_name=models.CharField(max_length=255, null=True)
    owner=models.CharField(max_length=50,null=True)
    mobile=models.CharField(max_length=10,null=True)
    city=models.CharField(max_length=55, null=True)
    address=models.CharField(max_length=300, null=True)
    locality=models.CharField(max_length=255, null=True)
    longitude=models.CharField(max_length=255, null=True)
    latitude=models.CharField(max_length=255, null=True)
    cuisines=models.CharField(max_length=300, null=True)

class employee(models.Model):
    first_name=models.CharField(max_length=50, null=True)
    last_name=models.CharField(max_length=50,null=True)
    email=models.CharField(max_length=100,null=True)
    mobile=models.CharField(max_length=10, null=True)
    password=models.CharField(max_length=100, null=True)

class business_opportunity(models.Model):
    restaurant_id=models.IntegerField(null=True)
    business_requirement=models.CharField(max_length=500,null=True)
    description=models.CharField(max_length=500,null=True)
    date_inserted=models.DateField(default=timezone.now)
    status=models.BooleanField(default=True)

class meeting(models.Model):
    restaurant_id=models.IntegerField(null=True)
    business_opportunity_id=models.IntegerField(null=True)
    employee_id=models.IntegerField(null=True)
    contacted_person=models.CharField(max_length=100,null=True)
    meeting_date=models.DateField(null=True)
    meeting_description=models.CharField(max_length=500,null=True)

def __str__(self):
	return self.name