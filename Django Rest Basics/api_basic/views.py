from http.client import RESET_CONTENT
from re import search
import re
from django.http import response
from django.shortcuts import get_object_or_404, render, resolve_url
from django.views.decorators.csrf import csrf_exempt
from rest_framework import permissions
from rest_framework import viewsets
from rest_framework.response import Response
from rest_framework.decorators import api_view, authentication_classes, permission_classes
from rest_framework.parsers import JSONParser
from rest_framework import status
from rest_framework.serializers import Serializer
from rest_framework.views import APIView
from rest_framework.authentication import BaseAuthentication, SessionAuthentication, BasicAuthentication, TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from rest_framework.viewsets import ViewSet

from .models import *
from .serializers import *

#Basic Views to handle API calls
"""
@csrf_exempt
def api_all_aticle_view(request):
    try:
        articles = Article.objects.all()
    except Article.DoesNotExist:
        return response(status=response.HttpResponseNotFound())
    
    if request.method == "GET":
        serializer = ArticleSerializer(articles, many=True)
        return Response(serializer.data)
    
    elif request.method == "POST":
        data = JSONParser().parse(request)
        serializer = ArticleSerializer(data=data)
        if serializer.is_valid():
            serializer.save()
            return response.JsonResponse(serializer.data, status=201)
        else:
            return response.JsonResponse(serializer.errors, status=400)

@csrf_exempt
def api_detail_aticle_view(request, pk):
    try:
        article = Article.objects.get(pk=pk)
    
    except Article.DoesNotExist:
        return response.HttpResponseNotFound()

    if request.method == "GET":
        serializers = ArticleSerializer(article)
        return response.JsonResponse(serializers.data, status=200)
    
    elif request.method == "PUT":
        data = JSONParser().parse(request)
        serializers = ArticleSerializer(article, data=data)
        if serializers.is_valid():

            serializers.save()
            return response.JsonResponse(serializers.data, status=200)
        else:
            return response.JsonResponse(serializers.errors, status=400)

    elif request.method == "DELETE":
        article.delete()
        return response.HttpResponse(status=204)
"""
        
# APi based views to handle API requests
""" @api_view(['GET','POST']) 
def api_all_aticle_view(request):
    try:
        articles = Article.objects.all()
        print(articles)
    except Article.DoesNotExist:
        return Response(status.HTTP_404_NOT_FOUND)
    
    if request.method == "GET":
        serializer = ArticleSerializer(articles, many=True)
        print(serializer.data)
        return Response(serializer.data, status.HTTP_200_OK)
    
    elif request.method == "POST":
        serializer = ArticleSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors, status.HTTP_400_BAD_REQUEST)

@api_view(['GET','PUT', 'DELETE']) 
def api_detail_article_view(request, pk):
    try:
        article = Article.objects.get(pk=pk)
    
    except Article.DoesNotExist:
        return Response(status.HTTP_404_NOT_FOUND)

    if request.method == "GET":
        serializers = ArticleSerializer(article)
        return Response(serializers.data, status.HTTP_200_OK)
    
    elif request.method == "PUT":
        serializers = ArticleSerializer(article, data=request.data)

        if serializers.is_valid():
            serializers.save()
            return Response(serializers.data, status.HTTP_200_OK)
        else:
            return Response(serializers.errors, status.HTTP_200_OK)

    elif request.method == "DELETE":
        article.delete()
        return Response(status.HTTP_204_NO_CONTENT) 
"""
# Class based views with DRF token authentication to handle API requests
class ClassApiAllArticleView(APIView):
    authentication_classes = [TokenAuthentication, SessionAuthentication, BasicAuthentication]
    permission_classes = [IsAuthenticated]
    def get(self, request):
        articles = Article.objects.all()
        serializer = ArticleSerializer(articles, many=True)
        return Response(serializer.data, status.HTTP_200_OK)

    def post(self, request):
        serializer = ArticleSerializer(data=request.data)

        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status.HTTP_201_CREATED)
        return Response(serializer.errors, status.HTTP_400_BAD_REQUEST)

class ListAllArticlesView(APIView):
    authentication_classes = [TokenAuthentication, SessionAuthentication, BasicAuthentication]
    permission_classes = [IsAuthenticated]

    def get(self, request):
        articles = Article.objects.all()
        serializer = ArticleSerializer(articles, many=True)
        return Response(serializer.data, status.HTTP_200_OK)
        pass
        
    def post(self, request):
        pass

class ClassApiDetailArticleView(APIView):
    def get_object(self, id):
        try:
            article = Article.objects.get(id=id)
            return article
    
        except Article.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
    
    def get(self, request, id):
        article = self.get_object(id)
        serializers = ArticleSerializer(article)
        return Response(serializers.data, status.HTTP_200_OK)
    
    def put(self, request, id):
        article = self.get_object(id)
        serializers = ArticleSerializer(article, data=request.data)

        if serializers.is_valid():
            serializers.save()
            return Response(serializers.data, status.HTTP_200_OK)
        return(serializers.errors, status.HTTP_400_BAD_REQUEST)
    
    def delete(self, request, id):
        article = self.get_object(id)
        article.delete()
        return Response(status.HTTP_204_NO_CONTENT)

#ViewSets
"""
class ListArticle(viewsets.ViewSet):
    permission_classes = [IsAuthenticated]
    queryset = Article.objects.all()

    def list(self, request):
        serializer = ArticleSerializer(self.queryset, many=True)
        return Response(serializer.data)

    def retrive(self, request, pk=None):
        article = get_object_or_404(self.request,pk=pk)
        serializer = ArticleSerializer(self.queryset, many=True)
        return Response(serializer.data)
"""