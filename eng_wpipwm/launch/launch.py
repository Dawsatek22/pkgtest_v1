from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='eng_wpipwm',
            namespace='eng_wpipwm',
            executable='pwm1',
            name='p1'
        ),
        Node(
            package='eng_wpipwm',
            namespace='eng_wpipwm',
            executable='pwm2',
            name='sim'
        ),
            ]
        )
    