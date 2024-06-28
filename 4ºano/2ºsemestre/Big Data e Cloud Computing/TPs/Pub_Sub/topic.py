def create_topic(project_id: str, topic_id: str, service_account_file: str) -> None:

    """Creating a new Pub/Sub topic."""

    # Importing libraries within function
    from google.cloud import pubsub_v1

    # Creating Pub/Sub Publisher Client, Specifying path of Topic
    publisher = pubsub_v1.PublisherClient.from_service_account_file(service_account_file)
    topic_path = publisher.topic_path(project_id, topic_id)

    # Creating a Topic Object at the topic_path
    topic = publisher.create_topic(request={"name": topic_path})

    # Printing the created Topic
    print(f"Created topic: {topic.name}")

    create_topic("bdcc2324-part2","myfirsttopic")