#include <rocketjoe/api/http.hpp>
#include "http.hpp"


namespace RocketJoe {
    namespace transport {


        http::http(transport_id id) : transport_base(transport_type::http, id) {

        }

        void http::header(std::string &&heder_name, std::string &&header_value) {
            headers_.emplace(std::move(heder_name), std::move(header_value));
        }

        void http::uri(const std::string &uri_) {
            this->uri_ = uri_;
        }

        void http::method(const std::string & method_) {
            this->method_= method_;
        }

        void http::body(const std::string & body_) {
            this->body_ = body_;
        }

        std::pair<http::header_const_iterator, http::header_const_iterator> http::headers() const {
            return std::make_pair(headers_.begin(),headers_.end());
        }

        std::string http::body() const {
            return body_;
        }

        http::~http() = default;

    }
}