# OOMps

Silly memory allocation in C++ to test the behaviour of VPA running in kube.

The main flaw with this application is that it does not account for the amount of memory consumed by the array of pointers it keeps for every allocated 4k block.

A pointer will consume 8 bytes of memory (64-bit) so the number of chunks allocated needs to be multiplied by 8 bytes in order to get the overhead memory footprint for keeping this array of pointers.

As this app is intended to test the behaviour of VPA, I have not addressed this issue. Setting the number of chunks to what I expect to see for xGB memory usage and the initial limits for the pod to be the same is fine in my case, as VPA will end up scaling the memory limits accordingly during my testing - even if it means the container will be OOMKilled until VPA scales its limits up.
