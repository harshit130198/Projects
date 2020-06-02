
from django.contrib import admin
from django.urls import path
from rest_framework.urlpatterns import format_suffix_patterns
from mosiac import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('employeeregistration/',views.employeeRegistration.as_view()),
    path('employeelogin/',views.employeeLogin.as_view()),
    path('restaurantnearby/',views.restaurantNearBy.as_view()),
    path('view_business_opportunity/',views.business_opportunityList.as_view()),
    path('view_meetings/',views.viewMeetingRecords.as_view()),
    path('add_meeting_record/',views.addMeetingRecords.as_view()),
    #path('employeelist/',views.employeeList.as_view()),
    #path('businessopportunity/',views.business_opportunityList.as_view()),
    #path('restaurantlist/',views.restaurantList.as_view()),
    #path('rest/',views.restaurantList,name="rest")

]
