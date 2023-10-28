from flask import Flask , request
from markupsafe import escape

app = Flask(__name__)

@app.route("/")
def root():
    return "<p> Main </p>"

@app.route("/variable/<int:id>")
def variable(id):
    return f"{escape(id)}" # usando escape para evitar code injection

@app.route("/login", methods=["GET", "POSST"])
def login():
    if request.method == 'POST':
        return f"Post method"

    elif request.method == 'GET':
        return f"Get method"

# ou pode separar dentro do decorator

@app.get("/get_method")
def get_method():
    return "get"

@app.post("/post_method")
def post_method():
    return "post"
