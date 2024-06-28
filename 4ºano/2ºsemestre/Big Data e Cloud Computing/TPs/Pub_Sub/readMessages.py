
def read_pubsub_messages(project_id: str, subscription_id: str, service_account_file: str):
    
    from google.cloud import pubsub_v1    
    # Initialize the Pub/Sub client
    subscriber = pubsub_v1.SubscriberClient.from_service_account_file(service_account_file)

    # Define the subscription path
    subscription_path = subscriber.subscription_path(project_id, subscription_id)

    def callback(message):
        # Process the received message
        print(f"Received message: {message.data}")
        # Acknowledge the message to mark it as processed
        message.ack()

    # Subscribe to the specified subscription and start receiving messages
    streaming_pull_future = subscriber.subscribe(subscription_path, callback=callback)

    print(f"Listening for messages on {subscription_path}...\n")

    # Keep the script running to continue receiving messages
    try:
        streaming_pull_future.result()
    except KeyboardInterrupt:
        streaming_pull_future.cancel()