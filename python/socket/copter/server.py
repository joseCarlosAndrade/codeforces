import socket

class SwarmServer:
    def __init__(self, host = "192.168.0.207", port = 5000):
        print(f"Starting server at {host} {port}")
        self.server_socket = socket.socket()  # get instance
        # look closely. The bind() function takes tuple as argument
        self.server_socket.bind((host, port))  # bind host address and port together

        # configure how many client the server can listen simultaneously
        self.server_socket.listen(2)
        self.conn, self.address = self.server_socket.accept()  # accept new connection
        print("Connection from: " + str(self.address))

    def send_message(self, message):
        self.conn.send(message.encode())

    def server_program(self):
        
        while True:
            # receive data stream. it won't accept data packet greater than 1024 bytes
            data = self.conn.recv(1024).decode()
            if not data:
                # if data is not received break
                break
            print("from connected user: " + str(data))
            data = input(' -> ')
            self.conn.send(data.encode())  # send data to the client

        self.conn.close()  # close the connection




if __name__ == '__main__':
    swarm_server = SwarmServer()
    # swarm_server.server_program()
    while True:
        try:
            message = input("Insira mensagem\n")
            if message == 'exit':
                break
            swarm_server.send_message(message)
        except Exception as err:
            print("Erro - ", err)
            break
    
    swarm_server.conn.close()


# import socket

# def run_server():
#     # Create a socket object
#     client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#     # Set up the server address and port
#     server_address = ('192.168.0.207', 5000)

#     try:
#         # Connect to the server
#         client_socket.connect(server_address)
#         print('Connected to {}:{}'.format(*server_address))

#         while True:
#             # Get the message to send
#             message = input('Enter a message to send: ')

#             # Send the message to the server
#             client_socket.send(message.encode())

#             if message.lower() == 'exit':
#                 break

#     except Exception as e:
#         print('An error occurred:', str(e))

#     finally:
#         # Close the connection
#         client_socket.close()
#         print('Connection closed')

# if __name__ == '__main__':
#     run_server()
