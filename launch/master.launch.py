import launch
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='theodolite_node',
            executable='theodolite_master',
            name='theodolite_master',
            output='screen',
            parameters=[
                {'rate': 5},
                {'show_data': True},
                {'number_of_theodolite': 3},
                {'number_first_synchronization': 20},
                {'delay_synchronization_theodolite': 300},
                {'delay_synchronization_between_theodolite': 5},
                {'number_others_synchronization': 5},
            ]
        )
    ])

if __name__ == '__main__':
    generate_launch_description()
