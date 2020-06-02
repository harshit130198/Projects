from django.shortcuts import render
from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.template.response import TemplateResponse
from django.shortcuts import get_object_or_404
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from . models import *
from . serializers import *
from . haversineformula import haversine


#Registration of employee storing data
class employeeRegistration(APIView):

	def get(self,request):
		return Response(status=200)

	def post(self,request):
		s = employeeSerializer(data=request.data)
		if s.is_valid():
			s.save()
		return Response(s.data, status=201)

#Login function for employee
class employeeLogin(APIView):

	def get(self,request):
		return Response(status=200)

	def post(self,request):
		data=request.data
		employees=list(employee.objects.values('id','email','password'))

		for i in range(0,len(employees)):
			for i in range(0,len(employees)):
				if(str(data.get('email')) == str(employees[i].get('email')) and str(data.get('password')) == str(employees[i].get('password'))):
					return Response({'employee_id':employees[i].get('id'),'valid':'True'},status=202)
		return Response({'valid':'False'},status=406)

#Location obtaining function for 
#API function to resturn nearby restaurants information //Working		
class restaurantNearBy(APIView):

	def get(self,request):
		return Response(status=200)

	def post(self,request):
		restaurant_to_display=[]
		rest_id_list=[]
		data=request.data
		latitude1=float(data.get('latitude'))
		longitude1=float(data.get('longitude'))
		restlocinfo=list(restaurant.objects.values('id','restaurant_name','owner','mobile','address','longitude','latitude'))
		business_opportunity_list=list(business_opportunity.objects.values('id','restaurant_id','business_requirement','description','status'))
		
		for i in range(0,len(business_opportunity_list)):	
			rest_id_list.append(business_opportunity_list[i].get('restaurant_id'))

		for i in range(0,len(restlocinfo)):
			latitude2=float(restlocinfo[i].get('latitude'))
			longitude2=float(restlocinfo[i].get('longitude'))
			dist=haversine(latitude1,longitude1,latitude2,longitude2)
			print(dist)
			if(dist<10 and restlocinfo[i].get('id') in rest_id_list):
				restaurant_dict={'restaurant_id':restlocinfo[i].get('id'), 'restaurant_name':restlocinfo[i].get('restaurant_name'), 
				'owner':restlocinfo[i].get('owner'),'mobile':restlocinfo[i].get('mobile'),'address':restlocinfo[i].get('address'),'distance':round(dist,2)}
				restaurant_to_display.append(restaurant_dict)
		print(restaurant_to_display)
		return Response(restaurant_to_display,status=302)

#API function to display business_opportuity of a specific restaurant
class business_opportunityList(APIView):

	def get(self,request):
		return Response(status=200)

	def post(self,request): 
		business_opportunity_list=list(business_opportunity.objects.values('id','restaurant_id','business_requirement','description','status'))
		business_opportunity_to_display=[]
		data=request.data

		for i in range(0,len(business_opportunity_list)):
			if(int(data.get('restaurant_id'))==business_opportunity_list[i].get('restaurant_id')):
				business_opportunity_id=business_opportunity_list[i].get('id')
				business_opportunity_restaurant_id=business_opportunity_list[i].get('restaurant_id')
				business_opportunity_requirement=business_opportunity_list[i].get('business_requirement')
				business_opportunity_description=business_opportunity_list[i].get('description')
				business_oppportunity_dict={'business_opportunity_id':business_opportunity_id, 'restaurant_id':business_opportunity_restaurant_id,
				'business_requirement':business_opportunity_requirement,'description':business_opportunity_description}
				business_opportunity_to_display.append(business_oppportunity_dict)
		print(business_opportunity_to_display)
		return Response(business_opportunity_to_display,status=201)

#API function to show meetingrecords
class viewMeetingRecords(APIView):

	def get(self,request):
		return Response(status=200) 

	def post(self, request, format=None):
		data=request.data
		meeting_list=list(meeting.objects.values('id','restaurant_id','business_opportunity_id','employee_id','contacted_person','meeting_date','meeting_description'))
		meeting_list_to_display=[]
		for i in range(0,len(meeting_list)):
			if(data.get('restaurant_id')==meeting_list[i].get('restaurant_id') and data.get('business_opportunity_id')==meeting_list[i].get('business_opportunity_id') ):
				meeting_id=meeting_list[i].get('id')
				meeting_emp_id=meeting_list[i].get('employee_id')
				contacted_person=meeting_list[i].get('contacted_person')
				meeting_date=meeting_list[i].get('meeting_date')
				meeting_description=meeting_list[i].get('meeting_description')
				meeting_dict={'meeting_id':meeting_id,'meeting_emp_id':meeting_emp_id,'contacted_person':contacted_person,'meeting_date':meeting_date,'meeting_description':meeting_description}
				meeting_list_to_display.append(meeting_dict)
		print(meeting_list_to_display)
		return Response(meeting_list_to_display,status=201)

#API function to add meeting records
class addMeetingRecords(APIView):

	def get(self,request):
		return Response(status=200) 

	def post(self, request, format=None):
		print(request.data)
		s = meetingSerializer(data=request.data)
		print(s.is_valid())
		if s.is_valid():
			s.save()
			return Response({'valid':'True'},status=201)
		return Response({'valid':'False'},status=406)

#API function to display employees details
class employeeList(APIView):
	def get(self,request):
		employees=employee.objects.all()
		serializer=employeeSerializer(employees,many=True)
		return Response(serializer.data)


'''
#Normal function for website to display restaurants id
def restaurantList(request):
	context=[]
	context=list(restaurant.objects.values('id'))
	print(context[0].get('id'))
	return render(request,"restaurantsdisplay.html")

#API Function to display restaurants id
class restaurantList(APIView):

	def get(self,request):
		context=[]
		context=list(restaurant.objects.values('id'))
		serializer=restaurantSerializer(context,many=True)
		return Response(context)  

class restaurantNearBy(APIView):
	def get(self,request):
		distancelist=[]
		restlocinfo=list(restaurant.objects.values('id','restaurant_name','longitude','latitude'))
		for i in range(0,len(restlocinfo)):
			longitude=float(restlocinfo[i].get('longitude'))
			latitude=float(restlocinfo[i].get('latitude'))
			dist=haversine(latitude,longitude)
			if(dist<5):
				rest_id=restlocinfo[i].get('id')
				rest_name=restlocinfo[i].get('restaurant_name')
				distancedict={'id':rest_id, 'restaurant_name':rest_name, 'distance':dist}
				distancelist.append(distancedict)
		return Response(distancelist)

class business_opportunityList(APIView):
	def get(self,request):
		businessopportunity=business_opportunity.objects.all()
		serializer=business_opportunitySerializer(businessopportunity,many=True)
		return Response(serializer.data) 

#API function to display all restaurants //COMPLETED
class restaurantList(APIView):

	def get(self,request):
		restaurants=restaurant.objects.all()
		serializer=restaurantSerializer(restaurants,many=True)
		return Response(serializer.data) 

class viewMeetingRecords(APIView):
	def get(self,request):
		meet=meeting.objects.all()
		serializer=meetingSerializer(meet,many=True)
		return Response(serializer.data) 

	def post(self, request, format=None):
		s = meetingSerializer(data=request.data)
		if s.is_valid():
			s.save()
		return Response(s.data, status=201)

'''
