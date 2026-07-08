import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PySubscriber(Node):
    def __init__(self):
        super().__init__('py_subscriber')
        self.subscription = self.create_subscription(
            String,
            'py_topic',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        self.get_logger().info(f'I heard: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = PySubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
