from os import name
from django.conf.urls import include
from django.contrib import admin
from django.urls import path
from . import views
from rest_framework.routers import DefaultRouter
from rest_framework.authtoken.views import obtain_auth_token

# Router for ViewSets 
""" app_name = 'api_basic'
router = DefaultRouter()
router.register('article', views.ListArticle, basename='user') """

# URLs patterns for basic views and apiviews 
""" urlpatterns = [ 
    path('', views.api_all_aticle_view, name='list' ),
    path('detail/<int:pk>/',views.api_detail_article_view, name='detail' )
] """

# URLs patterns for Class based views with DRF token authentication
urlpatterns = [ 
    path('list/articles/', views.ListAllArticlesView.as_view(), name='list_articles'),
    path('article-detail/<int:id>/',views.ClassApiDetailArticleView.as_view(), name='article_details' ),
    path('api-token-auth/', obtain_auth_token, name='api_token')
]


""" urlpatterns = [
    path('viewsets/', include(router.urls))
] """