# Generated by Django 2.1.4 on 2019-01-18 06:28

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('mosiac', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='restaurant',
            name='mobile',
            field=models.IntegerField(null=True),
        ),
        migrations.AddField(
            model_name='restaurant',
            name='owner',
            field=models.CharField(max_length=50, null=True),
        ),
    ]
