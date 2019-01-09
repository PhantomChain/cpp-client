/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HTTP_H
#define HTTP_H

#include <memory>
#include <string>
#include <cstring>

namespace Phantom {
namespace Client {
/***
 * Phantom::Client::HTTP
 * @brief: Forward Delcaration
 **/
class HTTP;
/**/

/***/

/***
 * Phantom::Client::AbstractHTTP
 *
 * The purpose of this class is to serve as an
 * entry point for integrating the HTTPClient
 * library for different boards/chipsets
 **/
class AbstractHTTP
{
    protected:
        char host_[17];
        int port_;
        int api_version_;

        AbstractHTTP() : host_(), port_(-1), api_version_(0) { }

        AbstractHTTP(AbstractHTTP&&) = delete;
        AbstractHTTP& operator=(AbstractHTTP&&) = delete;

        AbstractHTTP(const AbstractHTTP& other) : port_(other.port_), api_version_(other.api_version_) {
          strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
        }

        AbstractHTTP& operator=(const AbstractHTTP& other) noexcept {
          if (this != &other) {
            strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = other.port_;
            this->api_version_ = other.api_version_;
          }
          return *this;
        }

    public:
        virtual ~AbstractHTTP() {};

        /**/
        const char* host() const noexcept { return this->host_; };
        int port() const noexcept { return this->port_; };
        int api_version() const noexcept { return this->api_version_; }

        /**/

        virtual std::string get(
                const char *const request
        ) = 0;

        /**/

        virtual std::string post(
                const char *const request,
                const char *body
        ) = 0;

        /**/


        bool setHost(
                const char *const newHost,
                int newPort,
                int api_version
        ) {
            strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = newPort;
            this->api_version_ = api_version;
            return (this->port_ == newPort) && strcmp(this->host_, newHost);
        }
};
/**/

/***/

/***
 * HTTP object factory
 **/
std::unique_ptr<AbstractHTTP> makeHTTP();
/**/

};
};

/***
 * Phantom::Client::HTTP
 **/
class Phantom::Client::HTTP
{
private:
  std::unique_ptr<Phantom::Client::AbstractHTTP> http;

public:
  HTTP() : http(makeHTTP()) { }

  const char* host() const noexcept { return http->host(); };
  int port() const noexcept { return http->port(); };
  int api_version() const noexcept { return http->api_version(); };

  void setHostHTTP(
          const char* const newHost,
          int newPort,
          int api_version
  ) {
      http->setHost(newHost, newPort, api_version);
  }

  std::string get(
    const char* const request
  ) {
    return http->get(request);
  }

  std::string post(
    const char* const request,
    const char* body
  ) {
    return http->post(request, body);
  }
};
/**/

#endif
