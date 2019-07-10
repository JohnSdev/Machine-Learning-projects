WIP
Simple ML API to host a save_model model from Tensorflow.

The API cosists of an external API in python using Flask with a gunicorn server. 
The API will receive an image - preprocess the image and finally send the data to an internal API with Tensorflow Serving.

The result will then be sent back to the Python api and a final result will be sent to the user.



