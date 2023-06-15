import socket


def client_program():
    host = "192.168.0.207"  # as both code is running on same pc
    port = 5000  # socket server port number

    client_socket = socket.socket()  # instantiate
    client_socket.connect((host, port))  # connect to the server

    message = input(" -> ")  # take input

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  # send message
        data = client_socket.recv(1024).decode()  # receive response

        print('Received from server: ' + data)  # show in terminal

        message = input(" -> ")  # again take input

    client_socket.close()  # close the connection


if __name__ == '__main__':
    client_program()



# import socket

# def run_client():
#     # Create a socket object
#     server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#     # Set up the server address and port
#     server_address = ('192.168.0.207', 5000)
#     server_socket.bind(server_address)

#     # Listen for incoming connections
#     server_socket.listen(1)
#     print('Server is listening on {}:{}'.format(*server_address))

#     while True:
#         print('Waiting for a connection...')
#         client_socket, client_address = server_socket.accept()
#         print('Accepted connection from {}:{}'.format(*client_address))

#         try:
#             while True:
#                 # Receive the message from the client
#                 data = client_socket.recv(1024)
#                 if not data:
#                     break

#                 # Decode the received data
#                 message = data.decode()
#                 print('Received message:', message)

#                 # Process the message or perform any other desired actions

#         except Exception as e:
#             print('An error occurred:', str(e))

#         finally:
#             # Close the connection
#             client_socket.close()
#             print('Connection closed')

# if __name__ == '__main__':
#     run_client()