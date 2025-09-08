from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='subscriber', executable='velocity_node', name='velocity_node',
            output='screen',
        ),
        Node(
            package='publisher', executable='publisher_node', name='publisher_node',
            output='screen', 
        ),
    ])
