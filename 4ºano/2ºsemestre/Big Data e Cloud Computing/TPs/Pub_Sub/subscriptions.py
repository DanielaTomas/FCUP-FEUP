
def create_pull_subscription(project_id: str, topic_id: str, subscription_id: str, service_account_file: str) -> None:
    
    """Create a new pull subscription on the given topic."""
    # [START pubsub_create_pull_subscription]
    from google.cloud import pubsub_v1

    # TODO(developer)
    # project_id = "your-project-id"
    # topic_id = "your-topic-id"
    # subscription_id = "your-subscription-id"

    publisher = pubsub_v1.PublisherClient.from_service_account_file(service_account_file)
    subscriber = pubsub_v1.SubscriberClient.from_service_account_file(service_account_file)
    topic_path = publisher.topic_path(project_id, topic_id)
    subscription_path = subscriber.subscription_path(project_id, subscription_id)

    # Wrap the subscriber in a 'with' block to automatically call close() to
    # close the underlying gRPC channel when done.
    with subscriber:
        subscription = subscriber.create_subscription(
            request={"name": subscription_path, "topic": topic_path}
        )

    print(f"Subscription created: {subscription}")
    # [END pubsub_create_pull_subscription]




def create_push_subscription(project_id: str, topic_id: str, subscription_id: str, endpoint: str, service_account_file: str) -> None:
    
    """Create a new push subscription on the given topic."""
    # [START pubsub_create_push_subscription]
    from google.cloud import pubsub_v1

    # TODO(developer)
    # project_id = "your-project-id"
    # topic_id = "your-topic-id"
    # subscription_id = "your-subscription-id"
    # endpoint = "https://my-test-project.appspot.com/push"

    publisher = pubsub_v1.PublisherClient.from_service_account_file(service_account_file)
    subscriber = pubsub_v1.SubscriberClient.from_service_account_file(service_account_file)
    topic_path = publisher.topic_path(project_id, topic_id)
    subscription_path = subscriber.subscription_path(project_id, subscription_id)

    push_config = pubsub_v1.types.PushConfig(push_endpoint=endpoint)

    # Wrap the subscriber in a 'with' block to automatically call close() to
    # close the underlying gRPC channel when done.
    with subscriber:
        subscription = subscriber.create_subscription(
            request={
                "name": subscription_path,
                "topic": topic_path,
                "push_config": push_config,
            }
        )

    print(f"Push subscription created: {subscription}.")
    print(f"Endpoint for subscription is: {endpoint}")
    # [END pubsub_create_push_subscription]




def create_cloudstorage_subscription(project_id: str, topic_id: str, subscription_id: str, bucket: str, service_account_file: str) -> None:
    
    """Create a new CloudStorage subscription on the given topic."""
    # [START pubsub_cloudstorage_subscription]
    from google.cloud import pubsub_v1
    from google.protobuf import duration_pb2

    # TODO(developer)
    # project_id = "your-project-id"
    # topic_id = "your-topic-id"
    # subscription_id = "your-subscription-id"
    # bucket = "my-bucket"

    filename_prefix = "log_events_"
    filename_suffix = ".avro"
    # Either CloudStorageConfig.AvroConfig or CloudStorageConfig.TextConfig
    # defaults to TextConfig
    avro_config = pubsub_v1.types.CloudStorageConfig.AvroConfig(write_metadata=True)

    publisher = pubsub_v1.PublisherClient.from_service_account_file(service_account_file)
    subscriber = pubsub_v1.SubscriberClient.from_service_account_file(service_account_file)
    
    topic_path = publisher.topic_path(project_id, topic_id)
    subscription_path = subscriber.subscription_path(project_id, subscription_id)
    max_duration = duration_pb2.Duration()
    max_duration.FromSeconds(300)

    cloudstorage_config = pubsub_v1.types.CloudStorageConfig(
        bucket=bucket,
        filename_prefix=filename_prefix,
        filename_suffix=filename_suffix,
        avro_config=avro_config,
        # Min 1 minutes, max 10 minutes
        max_duration=max_duration,
        # Min 1 KB, max 10 GiB
        max_bytes=2000,
    )

    # Wrap the subscriber in a 'with' block to automatically call close() to
    # close the underlying gRPC channel when done.
    with subscriber:
        subscription = subscriber.create_subscription(
            request={
                "name": subscription_path,
                "topic": topic_path,
                "cloud_storage_config": cloudstorage_config,
            }
        )

    print(f"CloudStorage subscription created: {subscription}.")
    print(f"Bucket for subscription is: {bucket}")
    print(f"Prefix is: {filename_prefix}")
    print(f"Suffix is: {filename_suffix}")
    # [END pubsub_cloudstorage_subscription]