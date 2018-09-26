#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <err.h>
#include <event.h>
#include <evhttp.h>
#include <stdio.h>
#include <string>
using namespace std;

const int PORT = 31337;

void generic_handler(struct evhttp_request *req, void *arg)
{
    struct evbuffer *buf;
    int fd = -1;
    int sz = 0;
    FILE * fp;

    buf = evbuffer_new();
    if (buf == NULL)
        err(1, "failed to create response buffer");

    string s_req(evhttp_request_uri(req));  

    if (s_req.compare("/index500b.html") == 0) {
      fp = fopen("./resources/index500b.html", "r");
      fd = fileno(fp);
      fseek(fp, 0L, SEEK_END);
      sz = ftell(fp);
      evbuffer_add_file(buf, fd, 0, sz);
    } else if (s_req.compare("/index.html")==0){
      fp = fopen("./resources/index.html", "r");
      fd = fileno(fp);
      fseek(fp, 0L, SEEK_END);
      sz = ftell(fp);
      evbuffer_add_file(buf, fd, 0, sz);
    } else {
      evhttp_send_error(req, 404, "File not found");
    }
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
}

int main(int argc, char **argv)
{
    struct evhttp *httpd;
    event_init();
    httpd = evhttp_start("0.0.0.0", PORT);

    printf("Listening on port: %d\n", PORT);

    evhttp_set_gencb(httpd, generic_handler, NULL);

    event_dispatch();
    evhttp_free(httpd);
    
    return 0;
}